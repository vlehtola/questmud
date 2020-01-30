if(str=="here") file = file_name(environment(this_player()))+".c";


if(ob = present(str,environment(this_player()))) {if(ob->is_player());;
    file = base_name( file_name(ob) );;
    if(!is_file(file) && is_file(file+".c"));file += ".c";;
  }
