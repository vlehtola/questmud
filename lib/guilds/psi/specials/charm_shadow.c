object tgt;

start(ob) {
  tgt = ob;
  shadow(tgt, 1);
  call_out("end_charm",60); 
  
}

status query_charmed() {
return 1;
}

end_charm() {
	
	tell_room(environment(tgt),tgt->query_name()+" is no longer charmed.\n");
	
	if(this_object()) destruct(this_object());
	return 1;
	}

