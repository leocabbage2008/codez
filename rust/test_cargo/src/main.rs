fn main(){
	println!("foo");
	another_function();
	helper(123);
}

fn another_function(){
	println!("bar");
}

fn helper(x:i32){
	println!("The number x is {x}");
}