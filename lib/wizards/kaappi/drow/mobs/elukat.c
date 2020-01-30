inherit "obj/monster";
  reset(arg) {
  int a;
  a = random(4);
  ::reset(arg);
  if (arg) return;
  set_aggressive(0);

switch(a) {

case 0 : set_level(15+random(5)); 
         set_short("A cow");
         set_gender(2);
         set_animal(1);
         set_alias("cow"); 
         set_long("A cow is here eating some lichen.\n"+
                  "It is quite big and looks very heavy.\n"+
                  "It has a big pink udders.\n"); break;

case 1 : set_level(12+random(2));
         set_short("A sheep");
         set_gender(2);
         set_animal(1);
         set_alias("sheep"); 
         set_long("A quite small sheep. It has a thick\n"+
                  "white wool covering it.\n");break;

case 2 : set_level(8+random(5));
         set_short("A lamb");
         set_gender(2);
         set_animal(1);
         set_alias("lamb");
         set_long("A quite small lamb. It has a thick\n"+
                  "white wool covering it.\n");break;
 
case 3 : set_level(15+random(5));
         set_short("A ram");
         set_gender(1);
         set_animal(1);
         set_alias("ram");
         set_long("An angry looking old ram. It has \n"+
                  "quite sharp looking antlers and it\n"+
                  "is pawing the ground with its hoofs.\n");break;
 
 }
} 
