object poi,tp;

start(int bonus, object ob) {
  object poi;
  tp = ob;
  poi = present("poison_object", ob);
  if(!poi) { tell_object(tp, "Nothing happens.\n"); return 1; }
  poi->stop();
  return 1;
}

