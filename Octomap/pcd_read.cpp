#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <fstream>
#include <string>
using namespace std;

main (int argc, char** argv)
{



/*
   pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
   pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2 (new pcl::PointCloud<pcl::PointXYZ>);
   pcl::PointCloud<pcl::PointXYZ>::Ptr cloud3 (new pcl::PointCloud<pcl::PointXYZ>);


    if (pcl::io::loadPCDFile<pcl::PointXYZ> ("/home/s/Masaüstü/deneme/build/data/218.540000000.pcd", *cloud) == -1) //* load the file
    {
      PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
      return (-1);
    }
    if (pcl::io::loadPCDFile<pcl::PointXYZ> ("/home/s/Masaüstü/deneme/build/data/219.580000000.pcd", *cloud2) == -1) //* load the file
    {
      PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
      return (-1);
    }

    pcl::concatenateFields (*cloud,*cloud2, *cloud3);
    pcl::io::savePCDFile("data.pcd",*cloud3);


    return (0);

*/


ofstream myfile;
myfile.open ("example.pcd");



 myfile << "VERSION .7\nFIELDS x y z _ rgb _\nSIZE 4 4 4 1 4 1\nTYPE F F F U F U\nCOUNT 1 1 1 4 1 12\nWIDTH 640\nHEIGHT 480\nVIEWPOINT 0 0 0 1 0 0 0\nPOINTS 614400\nDATA binary\n";
                            

string okunan;
DIR *dir;
int dosya=0, nokta=0;
struct dirent *ent;
if ((dir = opendir ("data/")) != NULL) {
  while ((ent = readdir (dir)) != NULL) {
    okunan=ent->d_name;
    if(okunan.compare(".") && okunan.compare("..")){


      pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);

      if (pcl::io::loadPCDFile<pcl::PointXYZ> ("data/"+okunan, *cloud) == -1) //* load the file
      {
        PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
        return (-1);
      }
      std::cout << "Loaded "
                << cloud->width * cloud->height
                << " data points from test_pcd.pcd with the following fields: "
                << std::endl;







                for (size_t i = 0; i < cloud->points.size (); ++i)
                {
             /*   std::cout << "" << cloud->points[i].x
                            << " "    << cloud->points[i].y
                            << " "    << cloud->points[i].z << std::endl;

*/
                  myfile << "" << cloud->points[i].x
                            << " "    << cloud->points[i].y
                            << " "    << cloud->points[i].z << std::endl;
                            nokta++;
                }









      printf ("%d-%s\n",dosya,ent->d_name);
      dosya++;
    }

  }

  printf ("%d dosyadan %d nokta birleştirildi",dosya,nokta);
  closedir (dir);



} else {
  perror ("");
  return EXIT_FAILURE;
}







  	myfile.close();

  return (0);
}
