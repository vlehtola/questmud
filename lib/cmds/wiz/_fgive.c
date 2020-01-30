cmd_fgive(str) {
  object ob, target;
  string obj, tgt;
  if(sscanf(str,"%s to %s",obj, tgt) != 2) {
        write("Give what to who?\n");
        return 1;
  }
  ob = present(obj, this_player());
  if(!ob) {
    write("You don't have any "+obj+".\n");
    return 1;
  }
  target = present(tgt,environment(this_player()));
  if(!target) {
        write(tgt+" is not present.\n");
        return 1;
  }
  write("You give "+ob->short()+" to "+tgt+".\n");
  tell_object(target,this_player()->query_name()+" gives you "+obj+".\n");
  move_object(ob,target);
  this_player()->fix_weight();
  target->fix_weight();
  return 1;
}

