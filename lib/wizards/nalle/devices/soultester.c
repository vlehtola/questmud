reset(arg) {
  if(arg) return;
}
 
init() {
  add_action("givesoul", "givesoul");
}
 
givesoul(string str) {
object ob,obtwo;

if (!str) { write("You need to do that to someone.\n");  return 1; }

obtwo=clone_object("/wizards/nalle/soul/soul");
ob = find_living(str);
if (!ob) { write("No such player.\n");  return 1; }

tell_object(ob,"Nalle gives you a soul.\n");
write("You give "+ob->query_name()+" a soul.\n");
say("Nalle gives "+ob->query_name()+" a soul.\n");

move_object(obtwo, ob); 

return 1;
}


short() {
  return "Soulgiver";
}
 

id(str) {
  return str == "soulgiver";
}
 
long() {
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
