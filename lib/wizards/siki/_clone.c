#define SIMUL "/secure/simul_efun"

cmd_clone(string str) {   
  int tmp;
    object ob, clone_file; 
    if (!str) {
        write("##Usage: clone [ <file_name> | <object_name/id> ]\n");
        return 1; 
    } 
    if(sscanf(str, "local %s", str)) {
      ob = present(str, this_player());
      if(!ob) ob = present(str, environment(this_player() ));
      if(!ob) {
        write("No such local ob found.\n");
        return 1;
      }
      if(sscanf(file_name(ob), "%s#%d", str, tmp) != 2) {
        write("Target is not meant to be cloned.\n");
        return 1;
      }

    }
    str = (string)SIMUL->valid_read(str, this_player());
    if (!str) { 
          write("Sorry, no clone access.\n");
          return 1; 
    } 
    clone_file = str;
    write("FILE:"+clone_file+"\n"); 
    if(file_size(clone_file) < 1 && file_size(clone_file+".c") < 1) {
      write("No such file.\n");
      return 1;
    }
    ob = clone_object(clone_file);  
    say(this_player()->query_name() + " fetches something from another dimension.\n");
    if(!ob) {
      write("Object self-destructed.\n");
      return 1; 
    } 
    move_object(ob, environment(this_player()));
    if (call_other(ob, "get"))
        transfer(ob, this_player());
    write("You get " + str + " from an other dimension.\n");
    if (this_player()->query_wiz() == 1 ||
        this_player()->query_wiz() == 2) {
        log_file("CLONED_OB", "Cloner: " + this_player()->query_name() +
            ", Item: " + ob->short() + ".\n");
    } 
    return 1; 
}   

