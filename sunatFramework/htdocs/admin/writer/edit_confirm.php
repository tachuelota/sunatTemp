<?php
/*****************************************************************************
This is non public. 無断転載,無断使用を禁ず
Copyright (C) 2011. Sunatmark Co,.Ltd. All Right Reserved.

ファイル概要: 企業情報検索ユーザー管理　ユーザー管理一覧

$Id$
*****************************************************************************/

require	'const.inc';
require	'error.inc';
require 'MDB2.php';
require 'phplib5.inc';
require 'sub.inc';

session_start();

//カレントセッション
$sess = new SessionCurrent('*admin.user.list.edit');
$cur_ss = &$sess->vars;

$ref_sess = new SessionReference('*admin.user.list', SessionReference::MUST);
$ref_ss =& $ref_sess->vars;

$db = new mysql_db();
$where = '';
$arrWhere = array();

if ($_SERVER['REQUEST_METHOD'] == 'POST') error('アクセスエラー', '不正なアクセスです1', '/admin/writer');
if (array_key_exists('edit_input', $cur_ss)) {
    $tmpl_arr = $cur_ss['edit_input']['values'];
    
    //画像の表示
    if(!empty($cur_ss['edit_input']['values']['image'])){
        $file_image = '<img src="' . $cur_ss['edit_input']['values']['image'] . '" alt="' . $cur_ss['edit_input']['values']['name'] . '">';
    }else{
        $file_image = '';
    }

    $tmpl_arr += array('file_image' => $file_image);

}
else redirect("/admin/writer/");

$temp = new HTMLTemplate('admin/writer/edit_confirm.html');
echo $temp->replace($tmpl_arr);


?>