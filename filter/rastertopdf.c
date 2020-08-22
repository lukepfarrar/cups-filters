/*
 * Raster to pdf filter(based on rastertopdf() filter function).
 */


/*
 * Include necessary headers...
 */

#include "filter.h"


/*
 * Local globals...
 */

static int JobCanceled = 0;/* Set to 1 on SIGTERM */

/*
 * 'main()' - Main entry and processing of driver.
 */

int main(int argc, char *argv[])
{
  int ret;

  /*
   * Fire up the rastertopdf() filter function.
   */

  OutFormatType outformat = OUTPUT_FORMAT_PDF;
  ret = filterCUPSWrapper(argc, argv, rastertopdf, &outformat, &JobCanceled);

  if (ret)
    fprintf(stderr, "ERROR: rastertopdf filter failed.\n");

  return (ret);
}