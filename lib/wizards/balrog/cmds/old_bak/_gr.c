cmd_grep(string str) {
  int counta, countb, hits, pos, mfiles, start,i,x;
  string sstring, filename, fn, found_in;
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
  
  fn = fix_file(this_player(), filename);

  filenames = get_dir(fn);
  mfiles = sizeof(filenames);

  /* This check is cuz if you search for * you get the "." and ".." directories along... and that's not good. */
  if (fn == "*") { counta = 2; }

  for(counta;counta<mfiles;counta++) {
    fns += ({ fix_file(this_player(), filenames[counta]) });
  }
  counta = 0;
  filenames = fns;

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
  if (sizeof(explode(found_in, "\n")) > 1) {
    write("\nFound " + hits + " of \"" + sstring + "\" in files:\n" + found_in + "\n\n");
  } else {
    write("\nFound " + hits + " of \"" + sstring + "\" in file: " + found_in + "\n\n");
  }
  return 1;
}

string fix_file(object ob, string file) {
  string fn;

  fn = "/" +ob->query_current_path()+ "/" +file;
  if( file_size( fn ) != -1) { file = fn; }
  
  return file;
}
