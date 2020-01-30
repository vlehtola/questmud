#include "/wizards/astarel/areas/beldor/misc/conf.h" // conf-file.

inherit "obj/monster";

string *short_desc;
string *long_desc;
string *names;
object weapon;
int i;

reset(arg) {
  ::reset(arg);
  if(arg) return;

names = ({"servant","soldier","warrior"});
short_desc = ({
	       "A filthy orc servant",
	       "A orc soldier",
	       "A strong looking orc warrior",
              });
long_desc = ({
	      "tahan tulee\n"+
	      "descit\n",
              "2tahan tulee\n"+
	      "descit\n",
              "3tahan tulee\n"+
	      "descit\n",
             });

i = random(sizeof(names)); 

// Someday i'll change this to simple switch()
/** servant **/
if(i==0) {
move_object(clone_object(PATH+"objs/orcsci"),this_object());
init_command("wield scimitar");
move_object(clone_object(PATH+"objs/orcarmour"),this_object());
init_command("wear armour");
}

/** soldier **/

if(i==1) {
move_object(clone_object(PATH+"objs/orcmace"),this_object());
init_command("wield mace");
move_object(clone_object(PATH+"objs/orcarmour2"),this_object());
init_command("wear mail");
}

/** warrior **/
if(i==2) {
move_object(clone_object(PATH+"objs/orcba"),this_object());
init_command("wield axe");
move_object(clone_object(PATH+"objs/orcarmour3"),this_object());
init_command("wear mail");
}

    set_name("Orc "+names[i]);
    set_alias("orc");
    set_alt_name(names[i]);
    set_short(short_desc[i]);
    set_long(long_desc[i]);
    set_level(ORC1L+(i*1));
    set_race("orc");
   // set_al(-60);
   // set_al_aggr(50); // -10 - 100 aggroes?
   
}