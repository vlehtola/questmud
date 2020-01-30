cmd_man(what) {
    string word, word2;
    string *dirrit;
    int i;
    object pager;

    dirrit=({"/doc/LPC/","/doc/lfun/","/doc/efun/",
	     "/doc/w/","/doc/examples/"});
    
    if (!what) {
        cat("/doc/man");
        return 1;
    }
    if(what == "topics") {
      write("MANUAL TOPICS:\n");
      ls("/doc/LPC/");
      ls("/doc/lfun/");
      ls("/doc/efun/");
      ls("/doc/w/");
      ls("/doc/examples/");
      write("\n");
      return 1;
    }

    if (what && sscanf(what, "%s %s", word, word2) != 2) {

       for(i=0;i<(sizeof(dirrit);i++)              
        if (file_size(dirrit[i] + what) != -1) {
          word = read_file("/doc/helpdir/"+what , 0, 1000);
          write("\n");
          pager = clone_object("/daemons/pager");
          pager->move(this_object());
          pager->page(word);
          return 1;
        }

    }
    write("Try 'help' or 'help topics'.\n");
    return 1;
}

