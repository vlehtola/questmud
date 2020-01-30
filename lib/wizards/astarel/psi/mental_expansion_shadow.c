object liv;
int type, gain, delay;
status flaggi;

start(ob, effect, time) {
  liv = ob;
  gain = effect;
  delay = time;
  shadow(liv, 1);
  update_ep();
  flaggi = 1;
  call_out("remove_mentale", delay);
}

query_mentale() {
if(this_object() && flaggi == 1)return 1;

else return 0;
}

link_death() {
	liv->link_death();
	if(this_object())destruct_this_object();
}
    
remove_mentale() {

  tell_object(liv,"You have a strange feeling that your mental state just shrunk a bit.\n");
  liv->update_stats();
  flaggi = 0;
  this_object()->unshadow();
if(this_object())destruct_this_object();
}

death(arg) {
  liv->death(arg);
  flaggi = 0;
  this_object()->unshadow();
if(this_object())destruct_this_object();
}

update_ep() {
   liv->set_max_ep(liv->query_max_ep() + gain);
}
