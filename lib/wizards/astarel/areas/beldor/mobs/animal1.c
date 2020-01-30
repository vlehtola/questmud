#include "/wizards/astarel/areas/beldor/misc/conf.h" // conf-file.

inherit "obj/monster";

string *short_desc;
string *long_desc;
string *names;
int i;

reset(arg) {
  ::reset(arg);
  if(arg) return;

names = ({"ant","beetle","mole","rabbit","marmot","fox",});
short_desc = ({"An ant is carrying a piece of leaf",
	       "A beetle is rolling manure ball",
               "A mole is digging holes",
               "A rabbit is eating grass",
	       "A marmot is hanging around",
	       "A fox is searching a prey",
	       
              });
long_desc = ({
	      "tahan tulee\n"+
	      "descit\n",
              "2tahan tulee\n"+
	      "descit\n",
              "3tahan tulee\n"+
	      "descit\n",
	      "4tahan tulee\n"+
	      "descit\n",
	      "5tahan tulee\n"+
	      "descit\n",
	      "6tahan tulee\n"+
	      "descit\n",
             });

i = random(sizeof(names)); 

    set_name(capitalize(names[i]));
    set_alias(names[i]);
    set_short(short_desc[i]);
    set_long(long_desc[i]);
    set_level(ANI1l*(i+1));
    set_animal(1);
    set_al(10);
      
}