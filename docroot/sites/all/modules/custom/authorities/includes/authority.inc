<?php

class Authority {

	private $position = 0;
	private $entityID;
	private $latitude, $longitude;
	private $trading;
	private $environment;
	private $type;
	private $role;
	private $addr1, $addr2, $addr3;
	private $addressLine;
	private $postCode;
	private $telephone;
	private $mail;
	private $url;

	public function __construct() {	}

	public function setPosition($v) { $this->position = $v; return $this; }
	public function getPosition() { return $this->position; }
	public function getEntityID() { return $this->entityID; }
	public function getLatitude() { return $this->latitude; }
	public function getLongitude() { return $this->longitude; }
	public function getTrading() { return $this->trading; }
	public function getEnvironment() { return $this->environment; }
	public function getType() { return $this->type; }
	public function getRole() { return $this->role; }
	public function getAddr1() { return $this->addr1; }
	public function getAddr2() { return $this->addr2; }
	public function getAddr3() { return $this->addr3; }
	public function getAddressLine() { return $this->addressLine; }
	public function getPostCode() { return $this->postCode; }
	public function getTelephone() { return $this->telephone; }
	public function getMail() { return $this->mail; }
	public function getUrl() { return $this->url; }

	/**
	 * Instantiates an object from the Bing JSON response
	 * @param $json One Bing record in JSON
	 * @return The instantiated object
	 */
	static public function fromBing($json) {

		$o = new self();
		$o->entityID = $json['EntityID'];
		$o->latitude = $json['Latitude'];
		$o->longitude = $json['Longitude'];
		$o->trading = (bool) $json['Trading'];
		$o->environment = (bool) $json['Environment'];
		$o->type = $json['Type'];
		$o->role = $json['Role'];
		$o->addr1 = $json['Addr1'];
		$o->addr2 = $json['Addr2'];
		$o->addr3 = $json['Addr3'];
		$o->addressLine = $json['AddressLine'];
		$o->postCode = $json['PostalCode'];
		$o->telephone = $json['Telephone'];
		$o->mail = $json['Email'];
		$o->url = $json['URL'];

		return $o;
	}
}
