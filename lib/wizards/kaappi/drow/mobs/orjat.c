inherit "obj/monster";
  reset(arg) {
  object armour,weapon;
  int a;
  a = random(4);
  ::reset(arg);
  if (arg) return;
  set_aggressive(0);

switch(a) {

case 0 : set_level(15+random(5)); 
         set_short("A pitiful gnome slave");
         set_gender(1);
         set_race("gnome");
         set_alias("slave");
         set_long("The plain looking gnome. He is wearing only a ragged\n"+
                  "trousers but nothing else. His torso is full of scars.\n"+
                  "Some of those marks are quite fresh and are bleeding.\n"+
                  "His feets are bind together with chains and there is\n"+
                  "just an empty look in his brown eyes.\n");
break;

case 1 : set_level(15+random(8));
         set_short("A small dwarf slave");
         set_gender(1);
         set_race("dwarf");
         set_alias("slave"); 
         set_long("A small dwarf. He is wearing only a ragged\n"+
                  "trousers but nothing else. His torso is full of scars.\n"+
                  "Some of those marks are quite fresh and are bleeding.\n"+
                  "His feets are bind together with chains and there is\n"+
                  "just an empty look in his blue eyes.\n");
break;

case 2 : set_level(15+random(8));
         set_short("A hobbit slave");
         set_gender(1);
         set_race("hobbit");
         set_alias("slave");
         set_long("A young hobbit. He is wearing only a ragged\n"+
                  "trousers and shirt. His torso is full of scars.\n"+
                  "Some of those marks are quite fresh and are bleeding.\n"+
                  "His feets are bind together with chains and there is\n"+
                  "just an empty look in his green eyes.\n");
break;
 
case 3 : set_level(15+random(5));
         set_short("A human slave");
         set_gender(1);
         set_race("human");
         set_alias("slave");
         set_long("A young and starving boy. He is wearing only a ragged\n"+
                  "trousers but nothing else. His torso is full of scars.\n"+
                  "Some of those marks are quite fresh and are bleeding.\n"+
                  "His feets are bind together with chains and there is\n"+
                  "just an empty look in his brown eyes.\n");
break;
 
 }
} 
