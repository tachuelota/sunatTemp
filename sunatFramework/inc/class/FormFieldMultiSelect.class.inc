<?php declare(encoding = 'UTF-8');
/*----------------------------------------------------------------------------
�@�\�T�v: �����I���`�F�b�N
�@�\����:
	�����I���`�F�b�N����N���X

����:
	���O (I/O) ����
	$flag 	 	(I) �K�{���ǂ����Ȃǂ̃t���O
	$db		(I) db�I�u�W�F�N�g

�߂�l:
	�G���[���ЂƂł�������� true �A������Ȃ���� false
----------------------------------------------------------------------------*/
if (!defined('FORM_FIELD_MULTISELECT_CLASS_INC')): define('FORM_FIELD_MULTISELECT_CLASS_INC', 1);

class FormFieldMultiSelect extends FormField {
	protected $list;
	public function __construct(array $list, $flags = 0) {
		parent::__construct($flags);
		$this->list = $list;
	}
	
	public function check_value($value, array &$errors) {
		if ($this->flags & FormField::NOT_NULL) {
			if (is_null($value)) {
				$errors['is_null'] = TRUE;
				return;
			}
		}
		if (!is_null($value)) {
			foreach ( $value as $key => $val ) {
				if (!in_array($val, $this->list)) {
					$errors['bad_data'] = TRUE;
				}
			}
		}
	}
	public function convert_value($value) {
		if (is_null($value)) return null;
		return $value;
	}

};

endif/* FORM_FIELD_MULTISELECT_CLASS_INC */?>