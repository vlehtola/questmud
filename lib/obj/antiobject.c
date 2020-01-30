/* Object that is cloned inside equipment dropped by dead monsters,
and destroys them after a time if not touched (prevents too many objects
in a room bug). */

int i;
object target;
object envi;


id(str) { if(str == "antiobject") { return 1; } }

init_antiobject(object ob) {
   target = environment(this_object());
   if (!target) return;
   if(!target->query_weapon() && !target->query_armour()) {
     destruct(this_object());
     return;
   }
   envi = environment(environment(target));
   call_out("destroy_check", 3600);
   return 1;
}


destroy_check() {
   if (!target) { destruct(this_object()); return; }
   if (environment(target) == envi) {
      tell_room(environment(target), target->short() + " rots away.\n");
      if(target->query_value() > 1000 || target->query_stats()) {
        log_file("autodestructs", ctime(time()) + " " + target->short() +
 		" autodestructed in "+file_name(environment(target))+".\n");
      }
      destruct(target);
   }
   if(this_object()) destruct(this_object());
}
