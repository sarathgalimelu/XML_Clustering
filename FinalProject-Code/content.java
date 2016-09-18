import org.w3c.dom.*;
import org.w3c.dom.Element.*;
import javax.xml.parsers.*;
import java.io.*;
import org.xml.sax.*;
import javax.xml.transform.*; 
import javax.xml.transform.dom.DOMSource; 
import javax.xml.transform.stream.StreamResult;
import java.util.StringTokenizer;
public class content
{
  public static void main(String[] args)
  {
    try
    {
      //BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
      //System.out.print("xml file:--> ");
      //String st,str = bf.readLine();
	  BufferedReader in = new BufferedReader(new FileReader("input.txt"));
      String str=new String();
	  String st=new String();
	  //String tkn=new String();
	  String stp=new String();
      while((str= in.readLine())!=null)
      {
	  String words[]=new String[5000];
	  String arr[]=new String[100];
	  String d=new String();
	  int wc=0,flag,flg=0;
      st=str;
      File file = new File(st);
      if (file.exists())
      {
        DocumentBuilderFactory fact = DocumentBuilderFactory.newInstance();
        DocumentBuilder builder = fact.newDocumentBuilder();
        Document doc = builder.parse(str);
	    NodeList list = doc.getElementsByTagName("*");
	    FileWriter fp = new FileWriter("src/content.txt",true);
        str=str+".c.txt";
        fp.write(str+"\n");
        fp.close();
	    FileWriter out = new FileWriter(str);
	    for (int i=0; i<list.getLength(); i++) 
        {
          Element element = (Element)list.item(i);
	      NodeList fstNm = element.getChildNodes();
	      if((fstNm.getLength()-1)/2==0)
          {
			flag=0;
			String text = fstNm.item(0).getNodeValue();
            //System.out.println(fstNm.item(0).getParentNode().getNodeName()+" : "+text);
			words[wc++]=text;
			for(int g=0;g<wc-1;g++)
			{
            if(text.equals(words[g]))
			{
			flag=1;
			//System.out.println("Common Words"+text);
			break;
			}
			}
			if(flag==0)
			{
            StringTokenizer st1 = new StringTokenizer(text," ");
	        while(st1.hasMoreTokens())
			{
			flg=0;
			d=st1.nextToken();
			d = d.toLowerCase().trim();
			BufferedReader stop = new BufferedReader(new FileReader("stopwords.txt"));
			while((stp=stop.readLine())!=null)
            {
			stp = stp.toLowerCase();
			int strLen = d.length();
			int lastIdx = strLen - 1;
			String ret = d.substring(0, lastIdx);
			char last = d.charAt(lastIdx);
			char first = d.charAt(0);
			if((last ==',')||(last ==':')||(last =='?')||(last =='!')||(last =='.')||(last =='"')) 
			{
			d=ret.substring(0, strLen - 1);
            }
			if((first ==',')||(first =='?')||(first =='!')||(first =='.')||(first =='"')) 
			{
			int strLen1 = d.length(); 
			d=d.substring(1, strLen1);
            }
			if(d.equals(stp)==true)
			{
			flg=1;
			}
			}
			stop.close();
			if(flg!=1)
			{
			out.write(d+"\n");	
			}
			}
			}
          }
	    }
		    /*String q=new String();
			for(int g=0;g<wc;g++)
			{
			flag=0;
			q=words[g];
            for(int h=0;h<g;h++)
			{
            if(q.equals(words[h]))
			{
			flag=1;
			System.out.println("File not found!"+q);
			break;
			}
			}
			if(flag==0)
			{
			out.write(q+"\n");	
			}
			}*/
            out.close();
      }
      else
        System.out.println("File not found!");
		}in.close();
    }
    catch(Exception e){
      System.out.println("Exception"+e);}
  }
}
