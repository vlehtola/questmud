cmd_grep(string str) {
  int counta, countb, hits, pos, mfiles, i, x, start;
  string sstring, filename, fn, found_in, tmp;
  string *lines;
  string *filenames;
  string *fns;
  string *fins;

  counta = 0;
  countb = 0;
  hits = 0;
  mfiles = 0;
  start = 0;
  fns = ({});

  if (!str) { write("\nSyntax: grep \"<search string>\" <filename>\n\n"); return 1; }
  if (sscanf(str, "\"%s\" %s", sstring, filename) != 2) { write("\nSyntax: grep \"<search string>\" <filename>\n\n"); return 1; }
  
  if(filename != "*" && is_dir(filename) && filename[(strlen(filename)-1)..(strlen(filename)-1)] != "/") { filename += "/"; }
  if(filename != "*" && (file_size(filename) == -1) ) { fn = fix_file(this_player(), filename, filename); }
  else { fn = filename; }

  filenames = get_dir(fn);
  mfiles = sizeof(filenames);

  if (fn == "*") { counta = 2; }

  for(counta;counta<mfiles;counta++) {
    fns += ({ fix_file(this_player(), filenames[counta], fn) });
  }

  counta=0;
  filenames = fns;
  mfiles=sizeof(filenames);
  fns = ({});

  for(counta;counta<mfiles;counta++) {
    if(is_dir(filenames[counta])) {
      filenames -= ({ filenames[counta] });
      counta--;
    }
    mfiles = sizeof(filenames);
  }  

  mfiles = sizeof(filenames);
  counta=0;

  while(mfiles) {
    if( !( countb > (sizeof(filenames)-1) ) ) { 
      filename = filenames[countb]; 
      fns = read_file(filename,start,1000);
    }
    if(fns) { 
      lines = explode(fns, "\n"); 
      for(counta=0;counta < sizeof(lines);counta++) {
        if (strstr(lines[counta], sstring) != -1) {
          pos = strstr(lines[counta], sstring);
          write(filename + ": " +(counta+1+start)+ "," + pos + " : " + lines[counta] + "\n");
          hits++;
          if(!found_in) {
            found_in = filename; 
          } else {
            fins = explode(found_in, "\n");
            for(i=0;i<sizeof(fins);i++) {
              if(fins[i] != filename) { x = 1; } 
              else { x = 0; }
            }
            if(x) { found_in += "\n"+filename; }
          }
        }
      }
      start += 1000;
    } else {
      mfiles--; 
      countb++; 
      start = 0;
    }
  }
  if (sizeof(fins) > 1) {
    write("\nFound " + hits + " of \"" + sstring + "\" in files:\n" + found_in + "\n\n");
  } else {
    write("\nFound " + hits + " of \"" + sstring + "\" in file: " + found_in + "\n\n");
  }
  return 1;
}

string fix_file(object ob, string file, string orig) {
  string fn;
  string path;
  int tmp, y;
  tmp =0;

  path = "/"+ob->query_current_path()+ "/";

    if( strstr(orig,"/") != -1 ) {
      if (strstr(orig, "*") != -1 ) {
        y = strstr(orig, "*");
        for(y;y>0;y--){
          if(orig[y..y] == "/") { tmp = y; y=0; }
        }
        fn = orig[0..tmp]+file;      
      } else if(file_size(orig) != -1 && file_size(orig) != -2) {
        fn = orig;
      } else if(file_size(path+orig+file) != -1) {
        if (file == orig) { fn = path+file; }
        else { fn = path+orig+file; }
      } else {
        fn = orig+file;
      }
    } else if( file[0..0] != "/" ) { 
      fn = path+file; 
    } else { 
      fn = file; 
    }

    if( file_size( fn ) != -1 ) { file = fn; }
    if( file_size( path+fn ) != -1 ) { file = path+fn; }
    if( file_size( file ) == -2 && fn[(strlen(fn)-1)..(strlen(fn)-1)] != "/") { file = fn+"/"; }


  return file;
}

int is_dir(string str) {
  if(file_size(str) == -2) {
    return 1;
  }
  if(file_size("/"+str+"/") == -2) {
    return 1;
  }
  return 0;
}
