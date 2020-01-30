inherit "obj/armour";

start() {
  set_sub_type("helm");
  set_class(4);
  set_name("crown");
  set_short("A beautiful crown made of flowers");
  set_long("These beautiful and very frail decorative crowns are hand-made by florists.\n" +
           "The crown consists of different flowers carefully entwined together with\n" +
           "other very colourful flowers. Seems like it would look very funny on anyone\n" +
           "else than a child");

  set_value(1000);
  set_weight(20);
  set_stats("wis", 6);
  set_stats("spr", 10);
}
