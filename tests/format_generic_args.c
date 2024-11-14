#define CYE_IMPLEMENTATION
#include "cye.h"

int main(void) {

    {
        String_Slice ss = str_slice_make("Zero Terminated String");

        trace_info("Fomart=%s", fmt(ss));
        trace_info("tstring=%s", tstring(ss));
        trace_info(fmt(ss), ss_fmt_arg(ss));
    }

    {
        Cye_File_Stats stats = {0};
        file_stats(__FILE__, &stats);

        trace_info("Fomart=%s", fmt(stats));
        trace_info("tstring=%s", tstring(stats));
        trace_info(fmt(stats), file_stats_fmt_arg(stats));
    }

    {
        DString ds = {0};
        ds_write(&ds, "Diamonds ", "in ", "the ", "sky");

        trace_info("Fomart=%s", fmt(ds));
        trace_info("tstring=%s", tstring(ds));
        trace_info(fmt(ds), ds_fmt_arg(ds));
    }
    exit(1);
    return 0;
}
