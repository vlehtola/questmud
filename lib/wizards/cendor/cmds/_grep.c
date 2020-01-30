/* Cendor */
#pragma strict_types
#pragma save_types


mixed *del_array(mixed *array,int index);

string *lib_get_strings(string s);


status cmd_grep(string str) {
  string exp,dir,pathname,*tmp,*files,*lines;
  int i,j,k;

  if(!str) {
  write("## Usage:- grep <expression> <files>\n");
   return 1;
  }

    tmp = lib_get_strings(str);
    if(sizeof(tmp)!=2){
        write("## Useage:- grep <expression> <files>\n");
        return 1;
    }
    exp = tmp[0];
    dir = tmp[1];

  if(dir[0..0]!="/")
    dir="/" + (string)this_player()->query_path() + "/" + dir;
  tmp=explode(dir, "/");
  tmp=del_array(tmp, sizeof(tmp)-1);
  pathname=implode(tmp, "/");
  if(pathname[-1..-1]!="/") pathname+="/";
  files=get_dir(dir);
  if(!(j=sizeof(files))) {
    write("No files.\n");
    return 1;
  }
  for(i=0;i<j;i++) {
    string file;
    if(files[i]!="." && files[i]!="..") {
      file=read_file(pathname + files[i]);
      if(file && sizeof(explode(file, exp)) > 1) {
       write("## Found " + exp + " in: " + pathname + files[i] + "\n");
        lines=explode(file,"\n");
        for(k=0;k<sizeof(lines);k++)
          if(sizeof(explode(lines[k], exp)) > 1) {
                write(k+1+":"+lines[k]+"\n");
          }
      }
    }
  }
  return 1;
}

mixed *del_array(mixed *array,int index) {
 return array-=({array[index]});
}
 

string lib_fn_expand(string f1) 
{
string oldf1,tmp1,tmp2;
string *strarr;
int i,j;

    if(!f1)
        return "/"+this_player()->query_path();

    oldf1 = f1;
   
    /* expand '~/' to '/players/<wizname>/' */
    if (sscanf(f1,"~/%s",tmp1) == 1)
        f1 = "/players/"+this_player()->query_real_name()+"/"+tmp1;

    /* expand '~wizname/file' to '/players/wizname/file' */
    if (sscanf(f1,"~%s/%s",tmp1,tmp2)==2){
        if(file_size("/players/"+tmp1) == -2)
            f1 = "/players/"+tmp1+"/"+tmp2;
        else{
            write("Error: No such wiz as "+tmp1+".\n");
            return 0;
        }
    }   

    /* expand '~wizname' to '/players/wizname' */
    if (sscanf(f1,"~%s",tmp1)==1){
        if(tmp1 == "")
            f1 = "/players/"+this_player()->query_real_name();
        else if(file_size("/players/"+tmp1) == -2)
            f1 = "/players/"+tmp1;
        else{
            write("Error: No such wiz as "+tmp1+".\n");
            return 0;
        }
    }   
       
    /* current dir if not starting from root */
    if(f1[0..0]!="/")
        f1 = "/"+this_player()->query_path()+"/"+f1;

    /* Deal with '..' and '.' */
    strarr=explode(f1,"/");
    
    for(i=1;i<sizeof(strarr);i++){
        if(strarr[i]==".") strarr[i]=0;
        if(strarr[i]==".."){
            strarr[i]=0;
            for(j=i;!strarr[j]&&j;j--);
            if(j)
                strarr[j]=0;
            else{
                write("Error: Tried to access file below root directory.\n");
                return 0;
            }
        }
    }

    f1 = implode(strarr,"/");

  return f1;
}


void lib_failed() {
  write("Failed!\n");
  return;
}

int lib_file_exists(string f1) {
  int s1;

  s1 = file_size(f1);
  return (s1 >= 0);
}




string *lib_get_strings(string s){
string *sa, *ta, *ta2, ts;
int j,k,instr;

    if(!s) return ({});
    ta = explode(s,"\"");
    sa = ({});
    ts = "";
    instr = 0;
    for(k=0;k<sizeof(ta);k++){
        if(instr){
            ts += ta[k];
            if(!strlen(ts)){
                instr = 0;
            }else if(strlen(ts)>1 &&
                    ts[strlen(ts)-1]==92 &&
                    ts[strlen(ts)-2]==92){
                ts = ts[0..<2];
                sa += ({ ts });
                ts = "";
                instr = 0;
            }else if(ts[strlen(ts)-1]==92){
                ts = ts[0..<2]+"\"";
            }else{
                sa += ({ ts });
                ts = "";
                instr = 0;
            }                
        }else{
            ta2 = explode(ta[k]," ");
            for(j=0;j<sizeof(ta2);j++)
                if(strlen(ta2[j]))
                    sa += ({ ta2[j] });
            instr = 1;
        }
    }
    return sa;
}

