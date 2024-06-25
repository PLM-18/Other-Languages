<?php
   $severname = "localhost";
   $username = "myphpadmin";
   $password = "";
   $dbName = "users";

   $con = mysqli_connect($severname, $username, $password, $dbName);

   if(mysqli_connect_errno()){
    echo "Failed to connect!";
    exit();
   }
   echo "Connection success";

?>
