2017-8-8
 cmseasy的cut_image_action存在漏洞
 具体分析参照[这里](https://xianzhi.aliyun.com/forum/read/215.html)
 具体函数如下:
   ```php
   function cut_image_action() {
       $len = 1;
       if(config::get('base_url') != '/'){
           $len = strlen(config::get('base_url'))+1;
       }

       if(substr($_POST['pic'],0,4) == 'http'){
           front::$post['thumb'] = str_ireplace(config::get('site_url'),'',$_POST['pic']);
       }else{
           front::$post['thumb'] = substr($_POST['pic'],$len);
       }
       $thumb=new thumb();
       $thumb->set(front::$post['thumb'],'jpg');
       //直接引用，未做其它的过滤什么的，所以这一块很容易出现问题
       //当然 他们能想到如何利用也是叼叼的
       $img=$thumb->create_image($thumb->im,$_POST['w'],$_POST['h'],0,0,$_POST['x1'],$_POST['y1'],$_POST['x2'] -$_POST['x1'],$_POST['y2'$new_name=$new_name_gbk=str_replace('.','',Time::getMicrotime()).'.'.end(explode('.',$_POST['pic']));

       $save_file='upload/images/'.date('Ym').'/'.$new_name;
       @mkdir(dirname(ROOT.'/'.$save_file));
       ob_start();
       $thumb->out_image($img,null,85);
       file_put_contents(ROOT.'/'.$save_file,ob_get_contents());
       ob_end_clean();
       $image_url=config::get('base_url').'/'.$save_file;
       //$res['size']=ceil(strlen($img) / 1024);
       $res['code']="
                       //$('#cut_preview').attr('src','$image_url');
                       $('#thumb').val('$image_url');
                       alert(lang('save_success'));
       ";
       echo json::encode($res);
   }
   ```

```php
$new_name=$new_name_gbk=str_replace('.','',Time::getMicrotime()).'.'.end(explode('.',$_POST['pic'])
```
直接用了$_POST['pic']的后缀做为新文件的扩展名，应该就是这里导致的getshell
把后缀名改为php即可getshell

利用需要一点技巧:
 - php图像GD库处理后仍然保存shell语句，
 - php远程加载图片需要通过file_exists的验证

构造GD图片库的shell的代码[在此](https://github.com/Medicean/VulApps/blob/master/c/cmseasy/1/jpg_payload.php)

具体逻辑如下：
  - 先判断phpinfo里面是否包括gd库
  - 然后看不懂了:)
