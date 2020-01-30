inherit "obj/armour";
start() {
  set_class(6);
  set_value(5000);
  set_sub_type("leggings");
  set_short("Bone scale leggings named 'The Grim Layer'");
  set_long("Leggings are made of scales of some unknown creature's bones. Bones are not\n" + 
           "commonly recognized for armour-materials for their composive- and crudeness,\n" + 
           "but these scales look and feel really sturdy. And they weight much lesser\n" + 
           "than normal materials, such as steel and iron, used to make an armour. There\n" + 
           "is also some rumours going around about these leggings: The leggings were\n" + 
           "originally made by a Human smith named Krahom for paying his depts to one\n" + 
           "of the lesser lords in Hell. He even managed to get some materials straight\n" + 
           "from Hell to enhance the power of leggings. And as being a skillful smith, he\n" + 
           "completed few sets of leggings and succeeded to get away from his destiny at\n" + 
           "being slayed and dragged to the plains of Hell by one of its lesser lords");
  set_stats("str", 5);
  set_stats("dex", 3);
  set_stats("con", 8);
  set_stats("int", -2);
  set_resists("fire", 10);
  set_resists("cold", 10);
  set_resists("electric", 10);
}
