<?php
class Database {
	public $host=DB_HOST;
	public $username=DB_USER;
	public $password=DB_PASS;
	public $db_name=DB_NAME;
	//public $db;
	public $link;
	public $error;
	
	public function  __construct(){
		
		
		$this->connect();
		
		
	}
	private function connect(){
		 $this->link=new mysqli($this->host,$this->username,$this->password,$this->db_name);
		 $this->link->set_charset("utf8");
		 

		if(!$this->link){
			$this->error="connection failed: ".$this->link->connect_error;
			return false;
			
		}
	    	
		
		
	}

	public function select($query){
		$result=$this->link->query($query) or die($this->link->error.__LINE__ );
		
		if($result->num_rows >0)
		{
		   return $result;	
		}else {
			
		  return false;
		}
	}
		
	public function insert($query){
	  $insert_row=$this->link->query($query)  or die($this->link->error.__LINE__ );	
	  //validate insert
	  if($insert_row){
		  header("location : index.php?msg=".urlencode("Record Added"));
		  exit();
		  	  }
	  else {
		  die("Error : (".$this->link->errno." )".$this->link->error);
		  
		  
	  }
	  
	  
	}
	public function update($query){
	  $update_row=$this->link->query($query)  or die($this->link->error.__LINE__ );	
	  //validate insert
	  if($update_row){
		  header("location : index.php?msg=".urlencode("Record updated"));
		  exit();
		  	  }
	  else {
		  die("Error : (".$this->link->errno." )".$this->link->error);
		  
		  
	  }
	  
	  
	}
	
	public function delete($query){
	  $delete_row=$this->link->query($query)  or die($this->link->error.__LINE__ );	
	  //validate insert
	  if($delete_row){
		  header("location : index.php?msg=".urlencode("Record deleted"));
		  exit();
		  	  }
	  else {
		  die("Error : (".$this->link->errno." )".$this->link->error);
		  
		  
	  }
	  
	  
	}
	
	
	
	
	
	
}
