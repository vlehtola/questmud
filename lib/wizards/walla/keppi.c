reset(arg) {
  if(arg) return;
}
 
init() {
  add_action("summase", "summase");
  add_action("ampuaa", "ampuaa");
}
 
summase(string str) {
int i;
object ob;

write("You fidget with your remote control.\n");
say(this_player()->query_name() + "'s eyes light up as he plays with his remote control.\n"); 

if (!str) { write("You need to do that to someone.\n");  return 1; }

ob = find_living(str);
if (!ob) { write("No such player.\n");  return 1; }

if (221 < ob->query_level()) {
 write("Shit, the damn thing doesnt work :(.\n");
        return 1;
                                                      }
// Ok, iha riittavasti tsekkeja

if((ob->query_wiz() <= 3) || (!this_player()->query_wiz())) {
tell_object(ob,"You are sucked somewhere.\n");
write(ob->query_name()+" is sucked in by Walla's remote control.\n");
say(ob->query_name()+" is sucked in by Walla's remote control.\n");
move_object(ob, environment(this_player())); } else { return 0; }
return 1;
}


ampuaa(string str) {
int i;
object ob;

if (!str) { write("You need to do that to someone.\n");  return 1; }

ob = find_living(str);
if (!ob) { write("No such player.\n");  return 1; }

if(this_player()->query_name()!="Walla") {
write("Shit, what the fuck!?\n");
this_player()->reduce_hp(6666);
destruct(this_object());
return 1;
                                          }

write("You aim your remote at "+ob->query_name()+" and press the red button!\n");
say(this_player()->query_name() + " smirks evilly and presses a red button on his remote!\n"); 
tell_object(ob, "Walla shoots you with his duracell-powered remote control.\n");
ob->reduce_hp(6666);
return 1;
}
 


short() {
  return "Walla's remote control";
}
 

id(str) {
  return str == "remote";
}
 
long() {
  write("Lots of blinkenlichts! One says 'summase (player)'.\n");
  write("Another one says 'ampuaa (player)' If you are mortal\n");
  write("you do NOT want to play with this!\n");
}
 
drop() {
  return 0;
}
 

get() {
  return 1;
}
 

query_weight() {
  return 1;
}
