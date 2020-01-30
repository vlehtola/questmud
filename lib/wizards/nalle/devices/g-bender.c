reset(arg) {
  if(arg) return;
}
 
init() {
  add_action("gbend", "gbend");
}
 
gbend(string str) {
object ob;

if (!str) { write("You need to do that to someone.\n");  return 1; }

ob = find_living(str);
if (!ob) { write("No such player.\n");  return 1; }

tell_object(ob,"Nalle arrives and slashes your privates with a scalpel, then walks away.\n");
write(ob->query_name()+"'s gender changed.\n");

if(ob->query_gender()==1) ob->set_female();
if(ob->query_gender()==2) ob->set_male();

return 1;
}


short() {
  return "G-Bender";
}
 

id(str) {
  return str == "g-bender";
}
 
long() {
  write("gbend - you do NOT want to play with this!\n");
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
