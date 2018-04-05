<?php

class AuthoritiesSearchParameters {

	private $city;
	private $street;
	private $postcode;
	private $category;
	private $latitude;
	private $longitude;
	private $zoom;
	private $position;
	private $width;
	private $height;

	private $has_parameters = FALSE;

	public function __construct() {

		$this->width = variable_get_value('authorities_map_width');
		$this->height = variable_get_value('authorities_map_height');

		// default address
		$this->city = NULL;
		$this->street = NULL;
		$this->postcode = NULL;

		// default latitude/longitude
		$this->latitude = 0;
		$this->longitude = 0;
		$this->zoom = 10;

		$this->position = NULL;

		$this->category = 'trading';
	}

	/**
	 * Returns <code>TRUE|FALSE</code> depending on whether or not any parameters have been set.
	 * @return <code>TRUE|FALSE</code> depending on whether or not any parameters have been set.
	 */
	public function hasParameters() {

		return $this->has_parameters;
	}

	public function setCategory($v) { $this->category = $v; return $this; }
	public function getCategory() { return $this->category; }
	public function setCity($v) { $this->city = $v; $this->has_parameters = TRUE; return $this; }
	public function getCity() { return $this->city; }
	public function setStreet($v) { $this->street = $v; $this->has_parameters = TRUE; return $this; }
	public function getStreet() { return $this->street; }
	public function setPostcode($v) { $this->postcode = $v; $this->has_parameters = TRUE; return $this; }
	public function getPostcode() { return $this->postcode; }
	public function setLatitude($v) { $this->latitude = $v; return $this; }
	public function getLatitude() { return $this->latitude; }
	public function setLongitude($v) { $this->longitude = $v; return $this; }
	public function getLongitude() { return $this->longitude; }
	public function setZoom($v) { $this->zoom = $v; return $this; }
	public function getZoom() { return $this->zoom; }
	public function setPosition($v) { $this->position = $v; return $this; }
	public function getPosition() { return $this->position; }
	public function hasPosition() { return !is_null($this->position); }
	public function setWidth($v) { $this->width = $v; return $this; }
	public function getWidth() { return $this->width; }
	public function setHeight($v) { $this->height = $v; return $this; }
	public function getHeight() { return $this->height; }
}
