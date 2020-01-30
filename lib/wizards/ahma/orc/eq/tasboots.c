inherit "obj/armour";
start() {
  set_class(10);
  set_sub_type("boots");
  set_short("Sturdy steel boots with sharp tips");
  set_long("Steel boots with sharp tips. This kind of boots are commonly used by royal\n" +
           "knights who use full plate mails and other superior protective equipment.\n" +
           "The boots look very durable and strong, but they also seem to be very heavy.\n" +
           "Not much decoration is found on the boots, just numerous layers of sturdy-\n" +
           "looking steel plates on another");

  set_value(6000);
  set_weight(500);
  set_stats("str", 8);
  set_stats("dex", -2);
  set_stats("con", -2);
}