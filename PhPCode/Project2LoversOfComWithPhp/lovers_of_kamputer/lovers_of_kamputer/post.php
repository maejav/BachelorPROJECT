<?php include "includes/header.php"; ?>
<?php
$id=$_GET['id'];
//create db object 
$db=new Database();

//create a query 
$query='select * from posts WHERE id='.$id;
//Run query 
$post=$db->select($query)->fetch_assoc();



//create a query 
$query='select * from categories';
//Run query 
$categories=$db->select($query);
    ?>  
    <div class="blog-post">
            <h2 class="blog-post-title"><?php echo $post["title"];    ?></h2>
            <p class="blog-post-meta"><?php echo $post["date"];    ?> <a href="#"><?php echo $post["author"];    ?></a></p>
            <?php echo $post["body"];    ?>


               </div><!-- /.blog-post -->
    
         
<?php include "includes/footer.php"; ?>
          
    
