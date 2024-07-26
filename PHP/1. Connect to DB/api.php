<?php
	require_once 'config.php'
	$db = Database::getInstance();
	$conn = $db->getConnection();
	$data = json_decode(file_get_contents("php://input"), true);

	switch($data["type"]){
		case "register":
			if($data["username"] == ""){
				echo failed("Please fill in username");
				break;
			}
			
			if($data["password"] == ""){
				echo failed("Please fill in password");
				break;
			}			

			if($data["email"] == ""){
				echo failed("Please fill in email");
				break;
			}
			
			$username = $data["username"];
			$password = md5($data["password"]);
			$email = $data["email"];
			$stmt = $conn->prepare("INSERT INTO users (username, `password`, email) VALUES (?,?,?)");
			$stmt->bind_param("sss", $username, $password, $email);
			$stmt->execute();
			echo success("User registered successfully");
			break;
		case "login":
			if(!isset($data["username"]) || $data["username"] == ""){
				echo failed("Please fill in username");
			}

			if($data["password"] == ""){
				echo failed("Please fill in password");
				break;
			}

			echo success("User logged in successfully"):
			break;
	}

	function failed($message){
		return json_encode(array("status" => http_response_code(400), "message" => $message));
	}

	function success($message){
		return json_encode(array("status" => http_response_code(200), "data" => $message));
	}
?>
