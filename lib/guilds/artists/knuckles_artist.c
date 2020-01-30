/* New artist knuckle file coded by Celtron 10102005
  Includes a wc tune. Do not alter the weapon class.
 */

inherit "obj/weapon";

start()  {
    set_class(1);
    set_sub_type("knuckles {White}");
    set_name("knuckles");
set_alias("nyrkkirauta");
    set_short("Shining mithril combat knuckles {White}");
    set_long("Shining combat knuckles made of the finest mithril in the world.\n"
     "Every martial artists have their own knuckles which presents their\n"
     "You can destroy your knuckles with command: dest knuckles\n");
}
init() {
    ::init();
   add_action("dest", "dest");
}


int dest(string str) {
  if ( str == "knuckles" ) {
  write("You destroy your knuckles\n");
  destruct(this_object());
  return 1;
  }
}

drop() { return 1; }
query_no_save() { return 1; }

get_knuckle_sub_type(int i) {
  switch(i) {
  case 1..2: return "knuckles {White}";
  case 3: return "knuckles {Yellow}";
  case 4: return "knuckles {Green}";
  case 5: return "knuckles {Blue}";
  case 6: return "knuckles {Red}";
  case 7: return "knuckles {Black}";
  }
  return "knuckles {*BLACK*}"; 
}

set_knuckle_level(int i) {
  string str;
  if(i> 7) i=7;
  if(i< 1) i=1;
  str = get_knuckle_sub_type(i);
  set_class(i);
  set_sub_type(str);
  set_name("knuckles");
  set_short("Shining mithril combat "+ str);
    set_long("Shining combat knuckles made of the finest mithril in the world.\n"
     "Every martial artists have their own knuckles which presents their\n"
     "You can destroy your knuckles with command: dest knuckles\n");

}

/*
black.c:    set_sub_type("knuckles {Black}");
blue.c:    set_sub_type("knuckles {Blue}");
gm.c:    set_sub_type("knuckles {*BLACK*}");
green.c:    set_sub_type("knuckles {Green}");
knuckles_artist.c:    set_sub_type("knuckles {White}");
masters.c:    set_sub_type("knuckles {*BLACK*}");
red.c:    set_sub_type("knuckles {Red}");
testred.c:    set_sub_type("Shining mithril combat knuckles {2.Gup}");
white.c:    set_sub_type("knuckles {White}");
yellow.c:    set_sub_type("knuckles {Yellow}");
*/
