cmd_man(what) {
    string word, word2;
    string *dirrit;
    int i;
    object pager;

    dirrit=({"/doc/LPC/","/doc/lfun/","/doc/efun/",
             "/doc/w/","/doc/examples/","/doc/build/",
	     "/doc/wiz_help/"});
    
    if (!what) {
        cat("/doc/man");
        return 1;
    }
    if(what == "topics") {
      write("\tMANUAL TOPICS:\n\n");

      for(i=0;i<(sizeof(dirrit));i++)              
              ls(dirrit[i]);

      write("\n");
      return 1;
    }

    if (what && sscanf(what, "%s %s", word, word2) != 2) {

       for(i=0;i<(sizeof(dirrit));i++)              
        if (file_size(dirrit[i] + what) != -1) {
          word = read_file(dirrit[i]+what , 0, 1000);
        write("** QuestMUD manual 0.1 **************************"+
              "*************************\n\n");

          pager = clone_object("/daemons/pager");
          pager->move(this_object());
          pager->page(word);
          return 1;
        }
    }

    write("Try 'man' or 'man topics'.\n");
    return 1;
}

