<?php declare(encoding = 'UTF-8');
/*----------------------------------------------------------------------------
�@�\�T�v: �f�[�^�x�[�X�̓���e�[�u���̓���J�����ɁA�����l�������̂��Ȃ����`�F�b�N����
�@�\����:
	�f�[�^�x�[�X�̓���e�[�u���̓���J�����ɁA�����l�������̂��Ȃ����`�F�b�N����

����:
	���O (I/O) ����
	$flag 	 	(I) �K�{���ǂ����Ȃǂ̃t���O
	$db		(I) db�I�u�W�F�N�g

�߂�l:
	�G���[���ЂƂł�������� true �A������Ȃ���� false
----------------------------------------------------------------------------*/
if (!defined('FORM_FIELD_STRING_DB_DUPLICATE_CLASS_INC')): define('FORM_FIELD_STRING_DB_DUPLICATE_CLASS_INC', 1);

class FormFieldStringDbDuplicate extends FormFieldString {
	
	protected $db;
	protected $table;
	protected $field;
	protected $add_cond;
	
	public function __construct($flags = 0, $pattern = NULL, $min = NULL, $max = NULL, db $db, $table, $field, array $add_cond = array()) {
		parent::__construct($flags, $pattern, $min, $max);
		$this->db			= $db;
		$this->table		= $table;
		$this->field		= $field;
		$this->add_cond		= $add_cond;
	}
	
	public function check_value($value, array &$errors) {
		parent::check_value($value, $errors);
		if (!$errors) {
			$sql = "SELECT COUNT(*) AS cnt FROM ".$this->table." WHERE ".$this->field." = ?";
			$params = array($value);
			foreach ($this->add_cond as $cond_info) {
				$sql .= " AND ".$cond_info[0]." ".$cond_info[1]." ?";
				$params[] = $cond_info[2];
			}
			list($cnt) = $this->db->selectrow_array($sql, $params);
			if ($cnt > 0) $errors['duplicate'] = TRUE;
		}
	}
};

endif/* FORM_FIELD_STRING_DB_DUPLICATE_CLASS_INC */?>