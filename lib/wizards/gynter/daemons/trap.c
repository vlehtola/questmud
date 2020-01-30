/* * * * * * * * * * * * * * * * * * * * * *
 *                                         *
 * Daemon for traps((even random|cooming)) *
 * Mail bugs to Gynter (mudmail)           *
 * or by e-mail at:                        *
 * mathrim@hem1.passagen.se                *
 *                                         *
 * Created by : Gynter the Friendly? wiz.. *
 *                                         *
 * * * * * * * * * * * * * * * * * * * * * */

/* damage is defined in trap-file and is used for defining the amount of dam the trap is going to do
   active is defined in trap-file and is used for defining if the trap is active */
int damage, active;
/* short_desc is the short desc (surprise), long_desc - check short_desc, trigger - the text line that triggers the trap
   I was planning the coder would define in the trap file what the trigger line would be
   name,alias - the same as in any other ... items - extra look items ("lever, switch,blades :)") */
string short_desc, long_desc, trigger, name, alias, items;
/* execute_mess - the message displayed when you have triggered the trap and it's been activated
   deactive_mess - the message displayed when you deactivate the trap
   activ_mess - if the trap isn't activated at first then this mess is displayed when plr activate it */
string execute_mess, deactiv_mess, activ_mess;
query_name() { return name; }
query_active() { return active; }
query_trigger() { return trigger; }
query_damage() { return damage; }

reset(arg) {
  if (arg) return;
  this_object()->start();
}

short() {
return short_desc;
}

long(str) {
    int i;
    if (str == name || str == alias) {
       write(long_desc);
    return 1;
    }
    if (!items)
    return 1;
    i = 0;
    while(i < sizeof(items)) {
       if (items[i] == str) {
           tell_object(this_player(), items[i+1] + ".\n");
           return 1;
       }
       i += 2;
    }
}

execute() {
  if(!query_active()) return;
  if(this_player()->query_npc()) return;
  write(execute_mess);
  this_player()->hit_with_spell(damage);
  active = 0;
  return 1;
}

deactivate() {
  if(!query_active()) return;
  write(deactiv_mess);
  active = 0;
  return 1;
}

activate() {
  if(query_active()) return;
  if(this_player()->query_npc()) return;
  write(activ_mess);
  active = 1;
  return 1;
}

id(str) {
    int i;
    if (!items)
       return str == name || str == alias;
    while(i < sizeof(items)) {
       if (items[i] == str)
           return 1;
       i += 2;
    }
    return str == name || str == alias;
}

set_name(s) { name = s; }

set_alias(s) { alias = s; }

string s;
