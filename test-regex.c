#include "regex.h"
#include "dmalloc.h"

void print_string_range (const char *s, int b, int e)
{
    int i;
    for (i=b; i<e; i++)
        putc(s[i], stdout);
};

void tst2()
{
    const char* CFG_PAT="^trace_skip=([^!; ]*)!([^!; ]*)!([^!; ]*)([[:space:]])?(;.*)?$";
    regex_t trace_skip_pat;
    const char* buf=//"trace_skip=.*!netbios.dll!.* ; comment here\n";
    "trace_skip=\\%SystemRoot%\\System32.*!.*dll!.* ; skip all functions in 64-bit system DLLs\n";
    regmatch_t matches[4];
    int i;

    if (regcomp(&trace_skip_pat, CFG_PAT, REG_EXTENDED | REG_ICASE | REG_NEWLINE))
        die("failed regcomp() for pattern '%s'", CFG_PAT);

    printf ("dummy regexec() call -> %d\n", regexec (&trace_skip_pat, "\n", 4, matches, 0));
    printf ("dummy regexec() call -> %d\n", regexec (&trace_skip_pat, "", 4, matches, 0));

    if (regexec (&trace_skip_pat, buf, 4, matches, 0)==0)
    {
        for (i=0; i<4; i++)
        {
            printf ("%d %d [", matches[i].rm_so, matches[i].rm_eo); 
            print_string_range(buf, matches[i].rm_so, matches[i].rm_eo); 
            printf ("]\n");
        };
        //printf ("\n");
    };

    regfree (&trace_skip_pat);
};

int main(int argc, char **argv)
{
    char *pat = "^config=([^;]*)(;.*)?$";
    char *str = "config=asdasdasd; comment";
    
    regex_t r;
    regmatch_t m[2];

    if (regcomp(&r, pat, REG_EXTENDED | REG_NEWLINE))
        die("failed regcomp() for pattern '%s'", pat);
    if (regexec(&r, str, 2, m, 0))
        die("no match of pattern '%s' to string '%s'", pat, str);
    else
    {
        printf ("matched:\n");
        printf ("%d, %d\n", m[0].rm_so, m[0].rm_eo);
        printf ("["); print_string_range(str, m[0].rm_so, m[0].rm_eo); printf ("]\n");
        printf ("%d, %d\n", m[1].rm_so, m[1].rm_eo);
        printf ("["); print_string_range(str, m[1].rm_so, m[1].rm_eo); printf ("]\n");
    };

    //printf ("r=0x%p\n", &r);
    regfree (&r);

    tst2();

    dump_unfreed_blocks();
    dmalloc_deinit();

    return 0;
}
