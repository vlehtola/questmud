object tp;
start(int dama, object ob) {
tp = ob;
if(!tp->query_curse()) { tell_object(tp,"Nothing happens.\n"); return 1; }
tp->end_curse();
  return 1;
}

