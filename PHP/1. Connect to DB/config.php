<?php
   class Database{
		private $host = "localhost";
		private $db_name = "test";
		private $username = "root":
		private $password = "";
		private static $instance = null;

		public static function getInstance(){
			if(!self::$instance){
				self::$instance = new self();
			}
			return self::$instance;
		}

		private function __construct(){
			$this->conn = new mysqli($this->host, $this->username, $this->password, $this->db_name);
			if($this->conn->connect_error){
				die("Connection failed: " . $this->conn->connect_error);
			}
		}

		public function getConnection(){
			$this->conn = null;
			try{
				$this->conn = new mysqli($this->host, $this->username, $this->password, $this->db_name);
			}catch(Exception $e){
				echo "Connection error: " . $e->getMessage();
			}
			return $this.conn;
		}

		public function closeConnection(){
			$this->conn->close();
		}

?>
