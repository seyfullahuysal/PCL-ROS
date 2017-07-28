package pcl;

import java.io.*;
import java.util.StringTokenizer;
public class cOctree{
  public static void listTest(File dir) throws FileNotFoundException, IOException{
    File[] list=dir.listFiles();
    int width=0;
    int height=0;
    String line;
    for(int i=0;i<list.length;i++){
      System.out.println(list[i].getName());
      String deneme;
      deneme="/home/s/Masaüstü/deneme/build/data";
      deneme=deneme+"//"+list[i].getName();
      FileReader fileReader  = new FileReader(deneme);
      File file = new File("/home/s/Masaüstü/deneme/build/data/dosya.pcd");
      BufferedReader br = new BufferedReader(fileReader);
      FileWriter fileWriter = new FileWriter(file, true);
      BufferedWriter bWriter = new BufferedWriter(fileWriter);
      //width=width+Integer.parseInt(saydir(fileWriter, br))-1;
      //height=height+Integer.parseInt(saydirH(fileWriter, br));
      if(i==list.length-1)
      baslikYazdir(fileWriter,bWriter,640,480);
        bWriter.close();

        br.close();

  }
  for(int i=0;i<list.length;i++){
      System.out.println(list[i].getName());
      String deneme;
      deneme="/home/s/Masaüstü/deneme/build/data";
      deneme=deneme+"//"+list[i].getName();
      FileReader fileReader  = new FileReader(deneme);
      File file = new File("/home/s/Masaüstü/deneme/build/data/dosya.pcd");
      BufferedReader br = new BufferedReader(fileReader);
      FileWriter fileWriter = new FileWriter(file, true);
      BufferedWriter bWriter = new BufferedWriter(fileWriter);
        int sayac=0;
        bWriter = new BufferedWriter(fileWriter);
        line=null;
        for(int j=0;j<12;j++)
        {
          line = br.readLine();
        }
        while (line != null) {
               bWriter.write(line+"\n");
             if (!file.exists()) {
                file.createNewFile();

                }
             line = br.readLine();
        }
        bWriter.close();
        br.close();
    }
}
static String saydir (FileWriter fw, BufferedReader br)
{
  for(int i=0;i<6;i++)
  {
    try {
    br.readLine();
  } catch (IOException e) {
    // TODO Auto-generated catch block
    e.printStackTrace();
  }
  }
  String kelime[] = null;
  String sayi=new String();
  try {
  sayi=br.readLine();
  kelime=sayi.split(" ");
  System.out.print(kelime[1]);

  } catch (IOException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
	 return  kelime[1];
  }
  static String saydirH (FileWriter fw, BufferedReader br)
  {
	  for(int i=0;i<7;i++)
	  {
		  try {
			br.readLine();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	  }
	  String kelime[] = null;
	  String sayi=new String();
	  try {
		sayi=br.readLine();
		kelime=sayi.split(" ");
		System.out.print(kelime[1]);
	} catch (IOException e) {

  // TODO Auto-generated catch block
		e.printStackTrace();
	}
	 return  kelime[1];
  }
  static void baslikYazdir(FileWriter fw,BufferedWriter bw,int width,int height)
  {
	  try {
		bw.write("VERSION .7\nFIELDS x y z _ rgb _\nSIZE 4 4 4 1 4 1\nTYPE F F F U F U\nCOUNT 1 1 1 4 1 12\nWIDTH "+width+"\nHEIGHT "+height+"\nVIEWPOINT 0 0 0 1 0 0 0\nPOINTS "+(width*height)+"\nDATA binary\n");
	} catch (IOException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
  }
  public static void filterTest(File folder){
    FileFilter filter=new FileFilter(){
      public boolean accept(File file){
        return file.isFile();
      }
    };
    File[] normals=folder.listFiles(filter);
    for(int i=0;i<normals.length;i++){
      System.out.println(normals[i].getName());

      }
}
public static void main(String[] args) throws IOException{
  File dir=new File("/home/s/Masaüstü/deneme/build/data");
  listTest(dir);
  //filterTest(dir);
    System.out.println("bitti");
}
}
