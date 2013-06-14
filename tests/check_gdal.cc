/*!
 * Copyright 0000 <Nobody>
 * @file
 * @author David Matthew Mattli <dmattli@usgs.gov>
 *
 * @section LICENSE
 *
 * This software is in the public domain, furnished "as is", without
 * technical support, and with no warranty, express or implied, as to
 * its usefulness for any purpose.
 *
 * @section DESCRIPTION
 *
 * Tests the functionality of the GDAL library
 *
 */

#include <gtest/gtest.h>
#include <gdal_priv.h>

#include <vector>


TEST(GDALTest, ReadTiffFile) {
        std::string filename = "tests/testdata/veg_geographic_1deg.tif";

        GDALAllRegister();
        GDALDataset* ds = (GDALDataset *) GDALOpen( filename.c_str(), GA_ReadOnly );
        ASSERT_TRUE( ds != NULL);

        GDALClose(ds);
}

TEST(GDALTest, ReadGeoTiffTags) {
        std::string filename = "tests/testdata/veg_geographic_1deg.tif";
        
        GDALAllRegister();
        GDALDataset* ds = (GDALDataset *) GDALOpen( filename.c_str(), GA_ReadOnly );
        ASSERT_TRUE(ds != NULL);

        const char *georef = ds->GetProjectionRef();
        ASSERT_STRNE("", georef);
}
