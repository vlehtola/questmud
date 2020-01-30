#include <ansi.h>

inherit "obj/armour";
start() {
  set_class(10);
  set_sub_type("arm guards");
  set_name("bracers");
  set_short("Golden bracers named <"+sprintf("%c",27)+"[1;1;30m"+"Unbreakable"+OFF+">");
  set_long("These golden bracers shine with godly might,\n"+
            "it is certain that some enormous powers are\n"+
            "placed in these remarkable pieces of equipment.\n"+
            "The word 'Unbreakable' is engraved on them and\n"+
            "they surely look unbreakable. It is rumoured that\n"+             
            "these bracers protect the person who is wearing\n"+
            "them even from the greatest pain");

  set_value(5000);
  set_weight(100);
  set_stats("str", 5);
  set_stats("dex", -4);
  set_stats("con", 5);
  set_stats("spr", -5);
  set_resists("physical", 10);

}

