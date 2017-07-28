#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <fstream>
#include <string>
using namespace std;

int dosya_sayisi()
{

  string okunan;
  DIR *dir;
  int dosya=0, nokta=0;
  struct dirent *ent;
  if ((dir = opendir ("data/")) != NULL) {
    while ((ent = readdir (dir)) != NULL) {
      okunan=ent->d_name;
      if(okunan.compare(".") && okunan.compare("..")){

        dosya++;
      }

    }

    closedir (dir);


  }
  else
  {
    perror ("");
    return EXIT_FAILURE;
  }


    return dosya;

}
main (int argc, char** argv)
{




   pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2 (new pcl::PointCloud<pcl::PointXYZ>);
   cloud2->width    = 640*dosya_sayisi();
   cloud2->height   = 480;
   cloud2->is_dense = false;
   cloud2->points.resize (cloud2->width * cloud2->height*dosya_sayisi());



int index=0;
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
                  cloud2->points[nokta].x= cloud->points[i].x;
                  cloud2->points[nokta].y= cloud->points[i].y;
                  cloud2->points[nokta].z= cloud->points[i].z;
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




pcl::io::savePCDFileASCII ("test_pcd.pcd", *cloud2);



  return (0);
}
