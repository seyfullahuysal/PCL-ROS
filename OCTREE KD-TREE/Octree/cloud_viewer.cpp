#include <pcl/visualization/cloud_viewer.h>
#include <iostream>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
/////////////////////
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/openni_grabber.h>
#include <pcl/visualization/cloud_viewer.h>

#include <pcl/compression/octree_pointcloud_compression.h>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>


#include <pcl/octree/octree.h>
#include <vector>
#include <ctime>


using namespace std;
int user_data;

void viewerOneOff (pcl::visualization::PCLVisualizer& viewer)
{
    viewer.setBackgroundColor (1.0, 0.5, 1.0);
    pcl::PointXYZ o;
    o.x = 1.0;
    o.y = 0;
    o.z = 0;
    viewer.addSphere (o, 0.25, "sphere", 0);
    std::cout << "i only run once" << std::endl;

}

void viewerPsycho (pcl::visualization::PCLVisualizer& viewer)
{
    static unsigned count = 0;
    std::stringstream ss;
    ss << "Once per viewer loop: " << count++;
    viewer.removeShape ("text", 0);
    viewer.addText (ss.str(), 200, 300, "text", 0);

    //FIXME: possible race condition here:
    user_data++;
}

int
main ()
{

    bool showStatistics = true;
    pcl::io::OctreePointCloudCompression<pcl::PointXYZRGBA>* PointCloudEncoder;
    pcl::io::OctreePointCloudCompression<pcl::PointXYZRGBA>* PointCloudDecoder;

    pcl::io::compression_Profiles_e compressionProfile = pcl::io::HIGH_RES_OFFLINE_COMPRESSION_WITH_COLOR;

    // instantiate point cloud compression for encoding and decoding
    PointCloudEncoder = new pcl::io::OctreePointCloudCompression<pcl::PointXYZRGBA> (compressionProfile, showStatistics);
    PointCloudDecoder = new pcl::io::OctreePointCloudCompression<pcl::PointXYZRGBA> ();



    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZRGBA>);
    pcl::io::loadPCDFile ("/home/s/Masaüstü/PCL-ROS/OCTREE KD-TREE/Octree/data.pcd", *cloud);

    pcl::visualization::CloudViewer viewer("Cloud Viewer");




      std::stringstream compressedData;

      pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloudOut (new pcl::PointCloud<pcl::PointXYZRGBA> ());

// datayı sıkıştırmak için kullanılıyor.
      //PointCloudEncoder->encodePointCloud (cloud, compressedData);


     // PointCloudDecoder->decodePointCloud (compressedData, cloudOut);

// Octree için aşağıdaki yorum satırlarını aktif edip yukarıdaki 2 satırı yorum satırı yapmalıyız.

 float resolution = 128.0f;


 	 pcl::octree::OctreePointCloudSearch<pcl::PointXYZRGBA> octree (resolution);

 	 octree.setInputCloud (cloud);
 	 octree.addPointsFromInputCloud ();

viewer.showCloud (cloud);

    viewer.runOnVisualizationThreadOnce (viewerOneOff);


    viewer.runOnVisualizationThread (viewerPsycho);
    while (!viewer.wasStopped ())
    {
    	user_data++;
    }
    return 0;
}
