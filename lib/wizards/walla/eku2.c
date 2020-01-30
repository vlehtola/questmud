reset(arg) {
  if(arg) return;
}
 
init() {
  add_action("summase", "summase");
}
 
summase(string str) {
int i;
object ob;

write("You fidget with your remote control.\n");
say(this_player()->query_name() + "'s eye light up as he plays with his remote control.\n"); 

if (!str) { write("You need to do that to someone.\n");  return 1; }

ob = find_living(str);
if (!ob) { write("No such player.\n");  return 1; }

if (this_player()->query_level() < ob->query_level()) {
 write("Shit, the damn thing doesnt work :(.\n");
        return 1;
                                                      }
// Ok, iha riittavasti tsekkeja

if((ob->query_wiz() <= 3) || (!this_player()->query_wiz())) {
tell_object(ob,"You are sucked somewhere.\n");
write(ob->query_name()+" is sucked in by Walla's remote control.\n");
say(ob->query_name()+" is sucked in by Walla's remote control.\n");
move_object(ob, environment(this_player())); } else { destruct(this_player()); }
return 1;
}
 
short() {
  return "Walla's remote control.";
}
 

id(str) {
  return str == "remote";
}
 
long() {
  write("Lots of blinkenlichts! One says 'summase (player)'.\n");
}
 
drop() {
  return 0;
}
 

get() {
  return 1;
}
 

query_weight() {
  return 100;
}
