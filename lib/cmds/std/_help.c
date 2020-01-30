cmd_help(what) {
    string word, word2;
    object pager;
    if (!what) {
        cat("/doc/help");
        return 1;
    }
    if(what == "topics") {
      write("GENERAL:\n");
      ls("/doc/helpdir/");
      write("\n");
      return 1;
    }
    if(sscanf(what,"race %s", word) == 1) {
      call_other("/obj/race_selection", "info",word);
      return 1;
    }
    if(sscanf(what,"mastery %s", word) == 1) {
        if(!this_player()->query_mastery()[capitalize(word)] && !this_player()->query_wiz()) {
                write("You don't know such mastery.\n");
                return 1;
        }
        while(sscanf(word, "%s %s", word, word2) == 2) {
                word = lower_case(word +"_"+word2);
        }
        if(file_size("/doc/mastery/"+word) != -1) {
        cat("/doc/mastery/"+word);
        write("See also 'help masteries'\n");
        return 1;
    }
    write("No such mastery.\n");
    return 1;
    }
    if (sscanf(what,"skill %s", word) == 1) {
        string rounds,type;
        object skill;
        if (!this_player()->query_skills(word) && !environment(this_player())->get_skill_max(word, 0, 20)
                && !this_player()->query_wiz()) {
           write("You don't know such a skill.\nSee 'help skill' for additional information.\n");
           return 1;
        }
        while(sscanf(word, "%s %s", word, word2) == 2) {
            word = word +"_"+ word2;
        }
        if (file_size("/doc/skill/"+word) != -1) {
            cat("/doc/skill/"+word);
            write("See also 'help skill'\n");
            return 1;
        }
        if (file_size("/guilds/skills/"+word+".c") == -1) {
            write("No such a skill.\n");
            return 1;
        }
        return 1;
    }
    if (what && sscanf(what, "%s %s", word, word2) != 2) {
        if (file_size("/doc/helpdir/" + what) != -1) {
          word = read_file("/doc/helpdir/"+what , 0, 1000);
          write("\n");
          pager = clone_object("/daemons/pager");
          pager->move(this_object());
          pager->page(word);
          return 1;
        }

        if (file_size("/doc/w/" + what) != -1 && this_player()->query_wiz()) {
          word = read_file("/doc/w/"+what , 0, 1000);
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

