//
// xs.c -- (X)ML to C (S)truct conversion.
//
// Implements API function readXMLFile().

#include <ades.h>
#include <globals.h>

int readXMLFile(char *fn, observationBatch ** obs, char *schema)
{
  xmlDocPtr doc = xmlParseFile(fn);
  if (!doc)
    return -1;                  // xml functions emit error messages

  // printf("read okay\n");

  if (schema) {
    int r = tv(doc, schema);
    if (r) {
      // xmlSaveFormatFileEnc("debug.xml", doc, "UTF-8", 1);
      exit(r);                  // xml functions emit error messages
    }
    // printf("validate okay\n");
  }

  ts(doc, obs);
}
