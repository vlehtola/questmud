#define INVISIBILITY_D "/daemons/invisibility_d"

object user;
int time,type;

start(ob,ty,duration) {
  user = ob;
  type = ty;
  time = duration;
//  this_player()->set_invisible(1);
  shadow(user, 1);
  call_out("remove_invisibility",time);
}

query_invisibility_level() { return 1; }

query_invisible() 
{ 
 return INVISIBILITY_D->is_invis(	this_player(), 
					query_shadowing(this_object()),
					query_invisibility_level());
}

 /*

id(str) {
  if(this_player()->query_see_invisible() >= type) {
    return user->id(str);
  }
}

 */


remove_invisibility(silent) {
  if (!silent) {
    tell_object(user, "You feel solid.\n");
    tell_room(environment(user), user->query_name()+" turns visible!\n");
  }
//  this_player()->set_invisible(0);
  destruct(this_object());
}
