/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#ifndef BINARYDATA_H_103408023_INCLUDED
#define BINARYDATA_H_103408023_INCLUDED

namespace BinaryData
{
    extern const char*   bt_off_png;
    const int            bt_off_pngSize = 1615;

    extern const char*   bt_on_png;
    const int            bt_on_pngSize = 2017;

    extern const char*   bt_on2_png;
    const int            bt_on2_pngSize = 2076;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Number of elements in the namedResourceList array.
    const int namedResourceListSize = 3;

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes) throw();
}

#endif
