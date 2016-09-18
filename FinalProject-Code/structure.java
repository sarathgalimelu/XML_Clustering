import java.io.*;
import org.w3c.dom.*;
import org.w3c.dom.Element.*;
import org.xml.sax.*;
import javax.xml.parsers.*;
import javax.xml.transform.*;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
public class structure{
  public static void main(String[] args) {
    try{
      //BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
      //System.out.print("Enter xml file name: ");
      //String str = bf.readLine();
	  BufferedReader in = new BufferedReader(new FileReader("input.txt"));
	  String str=new String();
	  while((str=in.readLine())!=null)
	  {
      String parent[]=new String[5000];
      String node[]=new String[5000];
	  int arr[]=new int[5000],larr[]=new int[5000];
      NodeList fstNm[][]=new NodeList[5000][5000];
      File file = new File(str);
      if (file.exists()){
        DocumentBuilderFactory fact = DocumentBuilderFactory.newInstance();
        DocumentBuilder builder = fact.newDocumentBuilder();
        Document doc = builder.parse(str);
        NodeList list = doc.getElementsByTagName("*");
          int num=0,level,flag=0,f=0,z1=0;
          Element element = (Element)list.item(0);//root node
          node[num]=element.getNodeName();
          Node n=element.getParentNode();//root's parent node #doc
          parent[num]=n.getNodeName();
          fstNm[0][0] = element.getChildNodes();//childs of root
		  //System.out.println("Node no: "+num+ " has name " +element.getNodeName());
		  num++;
		  level=1;
		  
          if((fstNm[0][0].getLength()-1)/2!=0)
		  {
		  for(int i=1,j=0;i<fstNm[0][0].getLength();i+=2,j++)
          {
		  n=fstNm[0][0].item(i);
		  node[num]=n.getNodeName();
          parent[num]=n.getParentNode().getNodeName();
          fstNm[1][j] =n.getChildNodes();//childs of root
		  for(int k=0;k<(i-1)/2;k++)
		  {
		  if(node[num]==node[k+1])
		  flag=1;
		  if(flag==1)
		  break;
		  }
		  if(flag==1)
		  {
		  arr[num]=f;
		  larr[num]=level;
          //System.out.println("Node no: "+num+ " has name " +n.getNodeName()+" parent name "+n.getParentNode().getNodeName()+" "+level+" "+f);
		  }
		  else
		  {
		  f++;
		  arr[num]=f;
          larr[num]=level;
          //System.out.println("Node no: "+num+ " has name " +n.getNodeName()+" parent name "+n.getParentNode().getNodeName()+" "+level+" "+f);
		  }
		  flag=0;
		  num++;
		  }
		  }
		  level=2;

		  z1=z1+(fstNm[0][0].getLength()-1)/2;
		  int p1=0;
		  for(int k=1;k<fstNm[0][0].getLength();k+=2,p1++)
		  {
		  NodeList NL=fstNm[0][0].item(k).getChildNodes();
		  fstNm[1][p1] =NL;
		  for(int i=1,j=0;i<NL.getLength();i+=2,j++)
          {
		  n=NL.item(i);
		  node[num]=n.getNodeName();
          parent[num]=n.getParentNode().getNodeName();
		  for(int z=0;z<(i-1)/2;z++)
		  {
		  if(node[num]==node[z+1+z1])
		  flag=1;
		  if(flag==1)
		  break;
		  }
		  if(flag==1)
		  {
		  arr[num]=f;
		  larr[num]=level;
		  //System.out.println("Node no: "+num+ " has name " +n.getNodeName()+" parent name "+n.getParentNode().getNodeName()+" "+level+" "+f);
		  }
		  else
		  {
		  f++;
		  arr[num]=f;
		  larr[num]=level;
          //System.out.println("Node no: "+num+ " has name " +n.getNodeName()+" parent name "+n.getParentNode().getNodeName()+" "+level+" "+f);
		  }
		  flag=0;
		  num++;
		  }
		  z1=z1+(NL.getLength()-1)/2;
		  }
		  level=3;
		  int p2=0;
		  for(int k1=0;k1<p1;k1++)
		  for(int k=1;k<fstNm[1][k1].getLength();k+=2,p2++)
		  {
		  NodeList NL=fstNm[1][k1].item(k).getChildNodes();
		  fstNm[2][p2] =NL;
		  for(int i=1,j=0;i<NL.getLength();i+=2,j++)
          {
		  n=NL.item(i);
		  node[num]=n.getNodeName();
          parent[num]=n.getParentNode().getNodeName();
		  for(int z=0;z<(i-1)/2;z++)
		  {
		  if(node[num]==node[z+1+z1])
		  flag=1;
		  if(flag==1)
		  break;
		  }
		  if(flag==1)
		  {
		  arr[num]=f;   
		  larr[num]=level;
		 // System.out.println("Node no: "+num+ " has name " +n.getNodeName()+" parent name "+n.getParentNode().getNodeName()+" "+level+" "+f);
		  }
		  else
		  {
		  f++;
		  arr[num]=f;
		  larr[num]=level;
		  //System.out.println("Node no: "+num+ " has name " +n.getNodeName()+" parent name "+n.getParentNode().getNodeName()+" "+level+" "+f);
		  }
		  flag=0;
		  num++;
		  }
		  z1=z1+(NL.getLength()-1)/2;
		  }
		  level=4;
		  int p3=0;
		  for(int k1=0;k1<p2;k1++)
		  for(int k=1;k<fstNm[2][k1].getLength();k+=2,p3++)
		  {
		  NodeList NL=fstNm[2][k1].item(k).getChildNodes();
		  fstNm[3][p3] =NL;
		  for(int i=1,j=0;i<NL.getLength();i+=2,j++)
          {
		  n=NL.item(i);
		  node[num]=n.getNodeName();
          parent[num]=n.getParentNode().getNodeName();
		  for(int z=0;z<(i-1)/2;z++)
		  {
		  if(node[num]==node[z+1+z1])
		  flag=1;
		  if(flag==1)
		  break;
		  }
		  if(flag==1)
		  {
		  arr[num]=f;
		  larr[num]=level;
          //System.out.println("Node no: "+num+ " has name " +n.getNodeName()+" parent name "+n.getParentNode().getNodeName()+" "+level+" "+f);
		  }
		  else
		  {
		  f++;
		  arr[num]=f;
		  larr[num]=level;
		  //System.out.println("Node no: "+num+ " has name " +n.getNodeName()+" parent name "+n.getParentNode().getNodeName()+" "+level+" "+f);
		  }
		  flag=0;
		  num++;
		  }
		  z1=z1+(NL.getLength()-1)/2;
		  }
		  level=5;
		  int p4=0;
		  for(int k1=0;k1<p3;k1++)
		  for(int k=1;k<fstNm[3][k1].getLength();k+=2,p4++)
		  {
		  NodeList NL=fstNm[3][k1].item(k).getChildNodes();
		  fstNm[4][p4] =NL;
		  for(int i=1,j=0;i<NL.getLength();i+=2,j++)
          {
		  n=NL.item(i);
		  node[num]=n.getNodeName();
          parent[num]=n.getParentNode().getNodeName();
		  for(int z=0;z<(i-1)/2;z++)
		  {
		  if(node[num]==node[z+1+z1])
		  flag=1;
		  if(flag==1)
		  break;
		  }
		  if(flag==1)
		  {
		  arr[num]=f;		
          larr[num]=level;		  
          //System.out.println("Node no: "+num+ " has name " +n.getNodeName()+" parent name "+n.getParentNode().getNodeName()+" "+level+" "+f);
		  }
		  else
		  {
		  f++;
		  arr[num]=f;		  
		  larr[num]=level;
          //System.out.println("Node no: "+num+ " has name " +n.getNodeName()+" parent name "+n.getParentNode().getNodeName()+" "+level+" "+f);
		  }
		  flag=0;
		  num++;
		  }
		  z1=z1+(NL.getLength()-1)/2;
		  }
		  str=str+".s.txt";
		  FileWriter fi = new FileWriter("structure.txt",true);
		  fi.write(str+"\n");
		  fi.close(); 
		  //System.out.println(str);
		  FileWriter fo = new FileWriter(str);
          for(int i=1;i<num;i++)
          {
		  flag=0;
		  //System.out.println((i+1)+" "+node[i]+" "+parent[i]+" "+arr[i]);
		  for(int j=1;j<i;j++)
		  if((larr[i]==larr[j])&&(node[i]==node[j])&&(parent[i]==parent[j]))
		  flag=1;
		  if(flag==0)
		  fo.write(larr[i]+"\n"+node[i]+"\n"+parent[i]+"\n");
		  }
		  fo.close(); 
      }
      else{
        System.out.println("File not found!");
      }
	  }in.close();
    }
    catch(Exception e){
            System.out.println("Exception " + e);}
  }
}