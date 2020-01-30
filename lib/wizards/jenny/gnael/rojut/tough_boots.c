#include <ansi.h>

inherit "obj/armour";
start() {
  set_class(10);
  set_sub_type("boots");
  set_short("Boots of toughness <"+sprintf("%c",27)+"[1;1;34m"+"Warm"+OFF+">");
  set_long("Steel boots with sharp tips. This kind of boots are commonly used by royal\n" +
           "knights who use full plate mails and other superior protective equipment.\n" +
           "The boots look very durable and strong, but they also seem to be very heavy.\n" +
           "Not much decoration is found on the boots, just numerous layers of sturdy-\n" +
           "looking steel plates on another");

  set_value(5000);
  set_weight(100);
  set_stats("str", 1);
  set_stats("dex", 4);
  set_stats("con", 18);
  set_stats("spr", 1);
  set_resists("cold", 15);

}
