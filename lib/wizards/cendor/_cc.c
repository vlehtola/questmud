static status more(string file);

status cmd_update(string str, status no_reload) {
  object ob,tp;
int line;
  string rest, *files, file, format, path,logfile;
string name,foo;
  object env, *temp;
  int i, k;
  status flag;

  tp = this_player();
  if(!str) {
  str = "/"+ file_name(environment(tp));
    sscanf(str, "%s#%s", str, rest);
  }
  sscanf(str, "%s.c", str);
  str = tp->make_path(str);
  if(tp->bad_file(str)) {
    write("Illegal filename: "+ str +"\n");
    return 1;
  }
  for(i = strlen(str)-1; i && str[i] != '/'; i--);
  path = extract(str,0,i);
  file = extract(str,i+1);
#ifdef NO_GET_DIR_WILDCARDS
  format = wildcard_format(file+".c");
  files = (format_number(format)) ? get_dir(path +".") : get_dir(str +".c");
#else
  files = get_dir(str +".c");
#endif
  sscanf(path,"/%s",path);
  for(k = 0; k < sizeof(files); k++) {
#ifdef NO_GET_DIR_WILDCARDS
    if(!(file = match_format(files[k],format,format))) continue;
    file = path + file;
#else
    file = path + files[k];
#endif
    ob = find_object(file);
    if(!ob) {
      if(!no_reload) {
        flag = 1;
       if(sscanf(file,"players/%s/%s",name,foo) > 0)
         logfile = "/log/"+name;
       else
         logfile = "/log/log";
       rm(logfile);
        if(catch(call_other("/"+file,"???")));
        {
          tell_object(this_player(),"Failed to load "+ file +"\n");
          for(line = 1; cat(logfile, line, 45); line+=45);
        }
      }
      continue;
    }
    temp = all_inventory(ob);
    for(i = 0; i < sizeof(temp); i++) { /* move 'domain safe' to void */
#ifdef NATIVE_MODE
      if(query_ip_number(temp[i])) temp[i]->move(VOID);
#else
      if(query_ip_number(temp[i])) move_object(temp[i],VOID);
#endif /* NATIVE_MODE */
    }
    tell_object(this_player(),"Updating the old copy of: '"+file+"'\n");
    destruct(ob);
    for(i = 0; i < sizeof(temp); i++) {
      if(!i) { /* 1st iteration only needed */
        if(catch(call_other(file,"??"))) {
          tell_room(VOID, "You are in the Void.\n");
          break;
        }
      }
#ifdef NATIVE_MODE
      if(temp[i]) temp[i]->move(file);
#else
      if(temp[i]) move_object(temp[i], file);
#endif /* NATIVE_MODE */
    }
    flag = 1;
  }
  if(!flag) {
   tell_object(this_player(),"Error: No Loaded Files that match "+ str +"\n");
    return 1;
  }
  log_file("UPDATES", "File:"+ file +" was updated by "+
            tp->query_name(1)+", at time: "+
            ctime(time()) +"\n");
  return 1;
}

static status more(string file) {
  object ob, ob2;

  ob = clone_object(MORE_OB);
#ifdef NATIVE_MODE
  ob->move(this_object());
#else
  move_object(ob, this_object());
#endif /* NATIVE_MODE */
  ob->more(file);
  return 1;
}
