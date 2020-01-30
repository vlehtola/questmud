

inherit "obj/monster";
#define OWNER "Morgoth"

reset(arg) {
    object armour;
    ::reset(arg);
    if(arg) { return; }
    set_level(100);
    set_name("servant");
  set_alias("morgoth");
    set_short("The servant of Master "+OWNER);
    set_long("    |~|         /^^^\\         |~| \n"+
             "   _| |_       (|'o'|)       _| |_ \n"+
             " _| | | | _    (_---_)    _ | | | |_ \n"+
             "| | | | |' |    _| |_    | `| | | | | \n"+
             "|          |   /     \\   |          | \n"+
             " \\        /  / /(. .)\\ \\  \\        / \n"+
             "   \\    /  / /  ||.||  \\ \\  \\    / \n"+
             "     \\  \\/ /    || ||    \\ \\/  / \n"+
             "      \\__/     ooO Ooo     \\__/ \n");
    set_al(0);
    set_exp(0);
    set_aggressive(0);
}                  
heart_beat() {
object ob;
ob = find_player(lower_case(+OWNER+));

if(ob) {
  if(environment(ob) != environment(this_object())) {
    tell_room(environment(this_object()), "Servant follows "+OWNER+".\n");
    move_object(this_object(), environment(ob));
    tell_room(environment(this_object()),"Servant walks in after
"+OWNER+".\n");
  }
}
}

hit_player(int i) {
i = 0;
return ::hit_player(i); 
}

void catch_tell(string str) {
  string tmp, command, omistaja;
  if(sscanf(str,"%s says 'Servant, %s'", omistaja, command) != 2) return;
  if(omistaja != OWNER) return;

  if(sscanf(command,"smile %s",tmp)) {
    if(present(tmp,environment(this_object())))
      say(query_name()+" smiles happily at "+capitalize(tmp)+".\n");
    return;
  }

  if(sscanf(command,"hug %s",tmp)) {
    if(present(tmp,environment(this_object())))
      say(query_name()+" hugs "+capitalize(tmp)+" deeply.\n");
  return;
  }
}  
